#include <bits/stdc++.h>

using namespace std;
int col[1003];
void query (int st, int dr)
{
    int i;
    cout<<"? "<<dr-st+1<<' ';
    for(i=st;i<=dr;++i)
        cout<<i<<' ';
    cout<<'\n';
    cout.flush();
}
char idk[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int cnt=0;
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            if(a==k || b==k)
                ++cnt;
        }
        if(cnt==1 || n==1)
        {
            cout<<"Ayush\n";
            continue;
        }
        else
        {
            if(n%2==1)
            {
                cout<<"Ashish\n";
            }
            else
            cout<<"Ayush\n";
        }
    }
    return 0;
}