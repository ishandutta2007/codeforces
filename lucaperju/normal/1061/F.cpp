#include <bits/stdc++.h>
using namespace std;
long long n,depth;
vector <int> v;
vector <int> possible;
void query (int a, int b)
{
    v.clear();
    for(int i=1;i<=n;++i)
    {
        cout<<"? "<<a<<' '<<i<<' '<<b<<'\n';
        cout.flush();
        char c;
        cin>>c;
        if(c=='Y')
        {
            cin>>c>>c;
            v.push_back(i);
        }
        else
            cin>>c;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>n>>k;
    int cn=n;
    while(cn)
    {
        cn/=k;
        ++depth;
    }
    srand(time(NULL));
    int a,b;
    while(1)
    {
        a=((rand()%n+1)*((rand()^rand())%n+1+rand()))%n+1;
        b=((rand()%n+1)*((rand()^rand())%n+1+rand()))%n+1;
        query(a,b);
        if(v.size()==depth*2-1)
            break;
    }
    possible=v;
    for(i=0;i<possible.size();++i)
    {
        query(a,possible[i]);
        if(v.size()==depth)
        {
            cout<<"! "<<possible[i]<<'\n';
            cout.flush();
            return 0;
        }
    }
    return 0;
}