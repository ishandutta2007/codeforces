#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,a,b;
    cin>>b>>a>>n;
    long long int answer = (n+b-a+1)/2;
    if(answer>n+1) 
    {
        answer=n+1;
    }
    if(answer<0)
    {
        answer=0;
        //cout<<"YAay"<<endl;
    }
    if(n==0 && a>b)
    {
        answer=0;
    }
    else if(n==0 && b<a)
    {
        answer=1;
    }
    cout<<answer<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}