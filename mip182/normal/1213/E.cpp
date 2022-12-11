#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int n;
cin>>n;
string a,b;
cout<<"YES"<<endl;
cin>>a>>b;
if ((a[0]!=a[1])&&(b[0]!=b[1]))
{
for (char i='a';i<='c';i++)
{
for (char j='a';j<='c';j++)
{
for (char k='a';k<='c';k++)
{
if (i!=j && i!=k && j!=k){
string l="",r="";
l+=i;
l+=j;
r+=j;
r+=k;
if (a!=l&&a!=r&&b!=l&&b!=r)
{
for (int e=0;e<n;e++)
cout<<i;
for (int e=0;e<n;e++)
cout<<j;
for (int e=0;e<n;e++)
cout<<k;
return 0;}
}


}
}
}
}
else
{
if (a[0]!=a[1])
{
swap(a,b);
}
if (b[0]==b[1])
{
if (a[0]!=b[0]){
for (int i=0;i<n;i++)
cout<<b[0]<<a[0];
vector <char> d(3);
d[0]='a';
d[1]='b';
d[2]='c';
for (int i=0;i<3;i++)
{
if (d[i]==a[1]||d[i]==b[0])
d[i]='e';
}
char q='e';
for (int i=0;i<3;i++)
{
if (d[i]!='e')
q=d[i];
}
for (int i=0;i<n;i++)
cout<<q;
return 0;
}
else
{
if (a[0]=='a')
{
for (int i=0;i<n;i++)
cout<<'a'<<'b';
for (int i=0;i<n;i++)
cout<<'c';
return 0;
}
else
{
if (a[0]=='b')
{
for (int i=0;i<n;i++)
cout<<'a'<<'b';
for (int i=0;i<n;i++)
cout<<'c';
return 0;
}
else
{
for (int i=0;i<n;i++)
cout<<'c'<<'b';
for (int i=0;i<n;i++)
cout<<'a';
return 0;
 
}
    
}

}

}
else
{
if (a[0]==b[0])
{
vector <char> d(3);
d[0]='a';
d[1]='b';
d[2]='c';
for (int i=0;i<3;i++)
{
if (d[i]==a[1]||d[i]==b[1])
d[i]='e';
}
char q='e';
for (int i=0;i<3;i++)
{
if (d[i]!='e')
q=d[i];
}
for (int i=0;i<n;i++)
cout<<a[0]<<q;
for (int i=0;i<n;i++)
cout<<b[1];
return 0;
}
else
{
if (a[0]==b[1])
{
vector <char> d(3);
d[0]='a';
d[1]='b';
d[2]='c';
for (int i=0;i<3;i++)
{
if (d[i]==a[1]||d[i]==b[0])
d[i]='e';
}
char q='e';
for (int i=0;i<3;i++)
{
if (d[i]!='e')
q=d[i];
}
//cout<<a[0]<<" "<<q<<" "<<b[0]<<endl;
for (int i=0;i<n;i++)
cout<<a[0]<<q;
for (int i=0;i<n;i++)
cout<<b[0];
return 0;
}
else
{
for (int i=0;i<n;i++)
cout<<a[0]<<b[1];
for (int i=0;i<n;i++)
cout<<b[0];
return 0;
}
}
}
}}