#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,a[nmax];
bool sq(int x)
{
int k=sqrt(x);
if(k*k==x||(k-1)*(k-1)==x||(k+1)*(k+1)==x)return 1;
return 0;
}
int arr[nmax];
long long make_squares(int make)
{
long long ans=0;
int ind=0;
for(int i=1;i<=n;i++)
    if(sq(a[i])==0)
    {
    ind++;
    int x=sqrt(a[i]);
    arr[ind]=min(a[i]-x*x,(x+1)*(x+1)-a[i]);
    }
sort(arr+1,arr+ind+1);
for(int i=1;i<=make;i++)ans=ans+arr[i];
return ans;
}

long long remove_squares(int make)
{
long long ans=0;
int ind=0;
for(int i=1;i<=n;i++)
    if(sq(a[i])==1)
    {
    ind++;
    arr[ind]=(a[i]==0?2:1);
    }
sort(arr+1,arr+ind+1);
for(int i=1;i<=make;i++)ans=ans+arr[i];
return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];

int squares=0;
for(int i=1;i<=n;i++)
    if(sq(a[i]))squares++;
if(squares==n/2){cout<<0<<endl;return 0;}
if(squares<n/2)cout<<make_squares(n/2-squares)<<endl;
else cout<<remove_squares(squares-n/2)<<endl;
return 0;
}