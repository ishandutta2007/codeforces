#include<bits/stdc++.h>
using namespace std;
long long i,j,k,a,b,c,n;
string nephren_riddle_1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
//Original text What are you doing while sending ""? Are you busy? Will you send ""?
string nephren_riddle_2 = "What are you doing while sending ";
string nephren_riddle_3 = "? Are you busy? Will you send ";
string nephren_riddle_4 = "?";
//string test ="What are you doing while sending What are you doing at the end of the world? Are you busy? Will you save us?? Are you busy? Will you send What are you doing at the end of the world? Are you busy? Will you save us??";
unsigned long long sized[5];

unsigned long long quicksize[100005];

char look(unsigned long long aa, unsigned long long bb)
{
    if(bb>=quicksize[aa])
    {
        //cout<<bb<<" "<<bb-quicksize[aa]<<"NOOB";
        return '.';
    }
    else
    {
        if(aa==0)
        {
            return nephren_riddle_1.at(bb);
        } else if (bb<sized[1]-1)
        {
            return nephren_riddle_2.at(bb);
        } else if (bb==sized[1]-1)
        {
            return '"';
        } else if (bb<=sized[1]+quicksize[aa-1]-1)
        {
            return look(aa-1,bb-sized[1]);
        } else if (bb==sized[1]+quicksize[aa-1])
        {
            return '"';
        } else if (bb<quicksize[aa-1]+sized[2]-1)
        {
            return nephren_riddle_3.at(bb-sized[1]-quicksize[aa-1]-1);
        } else if (bb==quicksize[aa-1]+sized[2]-1)
        {
            return '"';
        } else if (bb<2*quicksize[aa-1]+sized[2])
        {
            return look(aa-1,bb-quicksize[aa-1]-sized[2]);
            //return 'z';
        } else if (bb==2*quicksize[aa-1]+sized[2]+1)
        {
            return '?';
        } else
        {
            return '"';
        }
    }
}

int main(){
    sized[1] = nephren_riddle_2.length()+1;
    sized[2] = nephren_riddle_3.length()+sized[1]+2;
    sized[3] = 2+sized[2];
    quicksize[0]=nephren_riddle_1.length();
    long long total = sized[3];
    for(i=1;i<=55;i++)
    {
        if(quicksize[i-1]<5e18){
        quicksize[i]=2*quicksize[i-1]+total;}
        else {
            quicksize[i]=1000000000000000008;
            //cout<<i<<"\n";
        }
    }
    for(i=56;i<=1e5;i++)
    {
        quicksize[i]=1000000000000000008;
    }
    //cout<<quicksize[999];
    cin>>n;
    for(a=1;a<=n;a++)
    {
        cin>>b>>c;
        //if(c!=1000000000000000000)
        cout<<look(b,c-1);
        //else cout<<look(b,c);
    }
    /*{
        cout<<look(1,a);
    }*/
    //cout<<look(1,quicksize[1]-1);
    //cout<<test.at(194);
}