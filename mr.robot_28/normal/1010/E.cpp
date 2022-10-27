#include<bits/stdc++.h>

using namespace std;

int xmax,ymax,zmax,n,m,k;

map< int , map< int , pair< int ,int > > > pmap;
vector< pair< int , map< int , pair< int ,int > > > > pvector;
vector< pair< vector< pair< int , pair< int , int > > > , vector< pair< int , int > > > > tree;
int oxl,oxr,oyl,oyr,ozl,ozr;

pair<int,int> comb(pair<int,int> p1,pair<int,int> p2)
{
    return make_pair(max(p1.first,p2.first),
                     min(p1.second,p2.second));
}

void build_y(int vx,int lxt, int rxt,int vy,int lyt, int ryt)
{
    if(lyt==ryt)
    {
        if(lxt==rxt)
            tree[vx].second[vy]=tree[vx].first[lyt].second;
        else
        {
            int sl,sr;
            sl=0,sr=tree[vx*2+1].first.size()-1;
            while(sr>sl)
            {
                int sm=(sl+sr)/2;
                if(tree[vx*2+1].first[sm].first>=tree[vx].first[lyt].first)
                    sr=sm;
                else
                    sl=sm+1;
            }
            pair<int,int> res1=(tree[vx*2+1].first[sl].first==tree[vx].first[lyt].first)?
                               (tree[vx*2+1].first[sl].second):
                                make_pair(0,(int)zmax+1);
            sl=0,sr=tree[vx*2+2].first.size()-1;
            while(sr>sl)
            {
                int sm=(sl+sr)/2;
                if(tree[vx*2+2].first[sm].first>=tree[vx].first[lyt].first)
                    sr=sm;
                else
                    sl=sm+1;
            }
            pair<int,int> res2=(tree[vx*2+2].first[sl].first==tree[vx].first[lyt].first)?
                               (tree[vx*2+2].first[sl].second):
                                make_pair(0,(int)zmax+1);
            tree[vx].second[vy]=comb(res1,res2);
        }
    }
    else
    {
        int myt=(lyt+ryt)/2;
        build_y(vx,lxt,rxt,vy*2+1,lyt,myt);
        build_y(vx,lxt,rxt,vy*2+2,myt+1,ryt);
        tree[vx].second[vy]=comb(tree[vx].second[vy*2+1],tree[vx].second[vy*2+2]);
    }
}

void build_x(int vx,int lxt, int rxt)
{
    if(lxt==rxt)
        tree[vx].first=vector< pair< int , pair< int , int > > >(pvector[lxt].second.begin(),pvector[lxt].second.end());
    else
    {
        int mxt=(lxt+rxt)/2;
        build_x(2*vx+1,lxt,mxt);
        build_x(2*vx+2,mxt+1,rxt);
        for(vector< pair< int , pair< int , int > > >::iterator i=tree[2*vx+1].first.begin(),j=tree[2*vx+2].first.begin();;)
        {
            if(i==tree[2*vx+1].first.end())
            {
                for(;j!=tree[2*vx+2].first.end();j++)
                    tree[vx].first.push_back(*j);
                break;
            }
            if(j==tree[2*vx+2].first.end())
            {
                for(;i!=tree[2*vx+1].first.end();i++)
                    tree[vx].first.push_back(*i);
                break;
            }
            if(i->first<j->first)
            {
                tree[vx].first.push_back(*i);
                i++;
            }
            else if(j->first<i->first)
            {
                tree[vx].first.push_back(*j);
                j++;
            }
            else
            {
                tree[vx].first.push_back(make_pair(i->first,comb(i->second,j->second)));
                i++;
                j++;
            }
        }
    }
    tree[vx].second.resize(tree[vx].first.size()*4);
    build_y(vx,lxt,rxt,0,0,tree[vx].first.size()-1);
}

pair<int,int> get_y(int vx, int vy, int lyt, int ryt, int lyc, int ryc)
{
    if(lyc>ryc)
        return make_pair(0,zmax+1);
    if(lyc==lyt&&ryt==ryc)
        return tree[vx].second[vy];
    int myt=(lyt+ryt)/2;
    return comb(get_y(vx,vy*2+1,lyt,myt,lyc,min(ryc,myt)),
                get_y(vx,vy*2+2,myt+1,ryt,max(lyc,myt+1),ryc));
}

pair<int,int> get_x(int vx, int lxt, int rxt, int lxc, int rxc, int ly, int ry)
{
    if(lxc>rxc)
        return make_pair(0,zmax+1);
    if(lxc==lxt&&rxt==rxc)
    {
        int sl,sr;
        sl=0,sr=tree[vx].first.size()-1;
        while(sr>sl)
        {
            int sm=(sl+sr)/2;
            if(tree[vx].first[sm].first>=ly)
                sr=sm;
            else
                sl=sm+1;
        }
        int lyc=sl;
        sl=0,sr=tree[vx].first.size()-1;
        while(sr>sl)
        {
            int sm=(sl+sr+1)/2;
            if(tree[vx].first[sm].first<=ry)
                sl=sm;
            else
                sr=sm-1;
        }
        int ryc=sr;
        return (tree[vx].first[lyc].first>=ly&&tree[vx].first[ryc].first<=ry)?
               get_y(vx,0,0,tree[vx].first.size()-1,lyc,ryc):
               make_pair(0,(int)zmax+1);
    }
    int mxt=(lxt+rxt)/2;
    return comb(get_x(vx*2+1,lxt,mxt,lxc,min(rxc,mxt),ly,ry),
                get_x(vx*2+2,mxt+1,rxt,max(lxc,mxt+1),rxc,ly,ry));
}

int main()
{
    scanf("%d%d%d%d%d%d",&xmax,&ymax,&zmax,&n,&m,&k);
    oxl=xmax;
    oxr=1;
    oyl=ymax;
    oyr=1;
    ozl=zmax;
    ozr=1;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        oxl=min(oxl,x);
        oxr=max(oxr,x);
        oyl=min(oyl,y);
        oyr=max(oyr,y);
        ozl=min(ozl,z);
        ozr=max(ozr,z);
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(oxl<=x&&x<=oxr&&oyl<=y&&y<=oyr&&ozl<=z&&z<=ozr)
        {
            printf("INCORRECT\n");
            exit(0);
        }
        map< int , pair< int ,int > >::iterator it=pmap[x].insert(make_pair(y,make_pair(0,zmax+1))).first;
        if(z<=ozr)
            it->second.first=max(it->second.first,z);
        if(z>=ozl)
            it->second.second=min(it->second.second,z);
    }
    printf("CORRECT\n");
    if(m>0)
    {
        pvector=vector< pair< int , map< int , pair< int ,int > > > >(pmap.begin(),pmap.end());
        tree.resize(pvector.size()*4);
        build_x(0,0,pvector.size()-1);
    }
    for(int i=0;i<k;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(oxl<=x&&x<=oxr&&oyl<=y&&y<=oyr&&ozl<=z&&z<=ozr)
        {
            printf("OPEN\n");
            continue;
        }
        if(m==0)
        {
            printf("UNKNOWN\n");
            continue;
        }
        bool closed=false;
        for(int ii=0;ii<=1;ii++)
            for(int jj=0;jj<=1;jj++)
            {
                if(closed)
                    break;
                int i=oxl+ii*(oxr-oxl);
                int j=oyl+jj*(oyr-oyl);
                int lx=min(x,i),rx=max(x,i);
                int sl,sr;
                sl=0,sr=pvector.size()-1;
                while(sr>sl)
                {
                    int sm=(sl+sr)/2;
                    if(pvector[sm].first>=lx)
                        sr=sm;
                    else
                        sl=sm+1;
                }
                int lxc=sl;
                sl=0,sr=pvector.size()-1;
                while(sr>sl)
                {
                    int sm=(sl+sr+1)/2;
                    if(pvector[sm].first<=rx)
                        sl=sm;
                    else
                        sr=sm-1;
                }
                int rxc=sr;
                if(pvector[lxc].first>=lx&&pvector[rxc].first<=rx)
                {
                    pair<int,int> p=get_x(0,0,pvector.size()-1,lxc,rxc,min(y,j),max(y,j));
                    if(min({z,ozl,ozr})<=p.first||max({z,ozl,ozr})>=p.second)
                        closed=true;
                }
            }
        if(closed)
            printf("CLOSED\n");
        else
            printf("UNKNOWN\n");
    }
}