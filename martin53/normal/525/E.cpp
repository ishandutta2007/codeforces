#include<bits/stdc++.h>
using namespace std;
const int nmax=26;
int n,k;
long long s;
int arr[nmax];
int stop;
long long ans=0;
long long fact[nmax];
vector<long long> numbers[nmax];
void generate_left(long long value,int marks,int position)
{
if(marks>k)return;
if(value>s)return;
if(position>stop)
{
    //cout<<marks<<" "<<value<<endl;
    numbers[marks].push_back(value);
    return;
}
generate_left(value,marks,position+1);
generate_left(value+arr[position],marks,position+1);
if(arr[position]<=18)generate_left(value+fact[arr[position]],marks+1,position+1);
}
void generate_right(long long value,int marks,int position)
{
if(marks>k)return;
if(value>s)return;
if(position>n)
{
    //cout<<"right: "<<value<<" "<<marks<<endl;
    int p,q;
    for(int other=0;other+marks<=k;other++)
    {
    p=lower_bound(numbers[other].begin(),numbers[other].end(),s-value)-numbers[other].begin();
    q=upper_bound(numbers[other].begin(),numbers[other].end(),s-value)-numbers[other].begin();
    ans=ans+q-p;
    }
    return;
}
generate_right(value,marks,position+1);
generate_right(value+arr[position],marks,position+1);
if(arr[position]<=18)generate_right(value+fact[arr[position]],marks+1,position+1);
}
int main()
{
cin>>n>>k>>s;
for(int i=1;i<=n;i++)cin>>arr[i];
fact[0]=1;
for(int i=1;i<19;i++)fact[i]=fact[i-1]*i;
stop=min(n,14);

generate_left(0,0,1);
for(int i=0;i<=k;i++)sort(numbers[i].begin(),numbers[i].end());
generate_right(0,0,stop+1);

cout<<ans<<endl;
return 0;
}