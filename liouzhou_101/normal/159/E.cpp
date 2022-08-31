#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n;

struct node
{
    int color,size,from;
}cube[MaxN];

inline bool cmp_node(const node &x,const node &y)
{
    return x.color<y.color||(x.color==y.color&&x.size>y.size);
}

int tot,num;
vector<long long> sum[MaxN],top[MaxN],most[MaxN];
vector<int> get[MaxN],from[MaxN],key[MaxN];

int p[MaxN];

inline bool cmp_size(const int &i,const int &j)
{
    return get[i].size()<get[j].size();
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&cube[i].color,&cube[i].size);
        cube[i].from=i;
    }
    sort(cube+1,cube+n+1,cmp_node);
    for (int i=1;i<=n;++i)
    {
        if (cube[i].color==cube[i-1].color) continue;
        ++tot;
        long long tmp=cube[i].size;
        sum[tot].push_back(tmp);
        get[tot].push_back(i);
        for (int j=i+1;j<=n;++j)
        {
            if (cube[j].color!=cube[i].color) break;
            tmp+=cube[j].size;
            sum[tot].push_back(tmp);
            get[tot].push_back(j);
        }
    }
    for (int i=1;i<=tot;++i)
        p[i]=i;
    sort(p+1,p+tot+1,cmp_size);
    long long ans=0;
    int get_1=0,get_2=0,len_1,len_2;
    for (int i=1;i<=tot;++i)
    {
        int len=get[p[i]].size();
        if (len==get[p[i-1]].size()) continue;
        ++num;
        for (int k=0;k<len;++k)
        {
            top[num].push_back(sum[p[i]][k]);
            from[num].push_back(p[i]);
        }
        long long first=sum[p[i]][len-1],second=0;
        int from_first=p[i],from_second=0;
        for (int j=i+1;j<=tot;++j)
        {
            if (get[p[j]].size()!=len) break;
            for (int k=0;k<len;++k)
                if (top[num][k]<sum[p[j]][k])
                {
                    top[num][k]=sum[p[j]][k];
                    from[num][k]=p[j];
                }
            if (sum[p[j]][len-1]>first)
            {
                second=first;
                from_second=from_first;
                first=sum[p[j]][len-1];
                from_first=p[j];
            }
            else if (sum[p[j]][len-1]>second)
            {
                second=sum[p[j]][len-1];
                from_second=p[j];
            }
        }
        if (second&&ans<first+second)
        {
            ans=first+second;
            get_1=from_first;
            get_2=from_second;
            len_1=len_2=len;
        }
    }
    for (int i=0;i<from[num].size();++i)
    {
        most[num].push_back(top[num][i]);
        key[num].push_back(from[num][i]);
    }
    for (int i=num-1;i>=1;--i)
    {
        if (ans<top[i][top[i].size()-1]+most[i+1][top[i].size()])
        {
            ans=top[i][top[i].size()-1]+most[i+1][top[i].size()];
            get_1=from[i][top[i].size()-1];
            get_2=key[i+1][top[i].size()];
            len_1=top[i].size();
            len_2=len_1+1;
        }
        for (int k=0;k<top[i].size();++k)
        {
            if (most[i+1][k]>top[i][k])
            {
                most[i].push_back(most[i+1][k]);
                key[i].push_back(key[i+1][k]);
            }
            else
            {
                most[i].push_back(top[i][k]);
                key[i].push_back(from[i][k]);
            }
        }
    }
    cout<<ans<<endl<<len_1+len_2<<endl;
    for (int i=0;i<len_1+len_2;++i)
    {
        if (i&1)
            printf("%d",cube[get[get_1][i>>1]].from);
        else
            printf("%d",cube[get[get_2][i>>1]].from);
        if (i<len_1+len_2-1) putchar(' ');
    }
    puts("");
    return 0;
}