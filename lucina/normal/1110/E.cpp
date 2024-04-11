#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<int> f1,f2;
int a[maxn],b[maxn],n,m,k;

int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++)
scanf("%d",&a[i]);
for(int i=1;i<=n;i++)
scanf("%d",&b[i]);
for(int i=2;i<=n;i++)
f1.push_back(a[i]-a[i-1]);
for(int i=2;i<=n;i++)
f2.push_back(b[i]-b[i-1]);
sort(f1.begin(),f1.end());
sort(f2.begin(),f2.end());
if(a[1]!=b[1]||a[n]!=b[n]||f1!=f2)
printf("No");
else
printf("Yes");


}