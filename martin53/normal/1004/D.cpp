#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int t,a[nmax];
int seen[nmax];
int my_seen[nmax];
void test_matrix(int n,int m,int x0,int y0)
{
    if(x0<=0||y0<=0||x0>n||y0>m)return;
    //cout<<"test matrix "<<n<<" "<<m<<" "<<x0<<" "<<y0<<endl;
    memset(my_seen,0,sizeof(my_seen));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        my_seen[abs(x0-i)+abs(y0-j)]++;

    for(int i=1;i<=n+m;i++)
        if(seen[i]!=my_seen[i])return;
    cout<<n<<" "<<m<<endl;
    cout<<x0<<" "<<y0<<endl;
    exit(0);
}
void test(int n,int m)
{
    if(seen[0]!=1)return;
    int mx=t;
    while(seen[mx]==0)mx--;
    int sum=mx+2;
    if(sum>n+m)return;
    int first_bad=1;
    while(seen[first_bad]==first_bad*4)first_bad++;
    //first_bad--;

    test_matrix(n,m,first_bad,sum-first_bad);
    test_matrix(n,m,sum-first_bad,first_bad);

    test_matrix(n,m,n+1-first_bad,sum-(n+1-first_bad));
    test_matrix(n,m,sum-(m+1-first_bad),m+1-first_bad);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>t;
for(int i=1;i<=t;i++)
{
cin>>a[i];
seen[a[i]]++;
}

for(int i=1;i<=t;i++)
    if(seen[i]==0&&seen[i+1])
    {
        cout<<-1<<endl;
        return 0;
    }
//for(int i=0;i<=5;i++)cout<<seen[i]<<" ";cout<<endl;

for(int n=1;n*n<=t;n++)
    if(t%n==0)test(n,t/n);

cout<<-1<<endl;
return 0;
}