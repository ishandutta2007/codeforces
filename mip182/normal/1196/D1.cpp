#include <bits/stdc++.h>
typedef long long ll;
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 100000;
const long long kek=998244353;

int main() {
mipletsplay;

string rgb="";
for (int i=0;i<1000;i++)
{
rgb+="RGB";    
}
//cout<<rgb;
string r[3];
r[0]=rgb.substr(0,2002);
r[1]=rgb.substr(1,2003);
r[2]=rgb.substr(2,2004);
int q;
cin>>q;
for (int i=0;i<q;i++)
{
int n,k;
cin>>n>>k;
string s;
cin>>s;
int answer=INF;
for (int j=0;j<=n-k;j++)
{
for (int h=0;h<3;h++)
{
int chet=0;
for (int g=0;g<k;g++)
{
if (s[j+g]!=r[h][g]){   
chet++;
//cout<<s[j+g]<<endl;
}
}
answer=min(answer,chet);    
    
    
}
  
}



cout<<answer<<endl;
}

}