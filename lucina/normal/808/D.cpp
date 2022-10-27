#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],n;
long long sum,s;
map<long long,bool> f;

int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),sum+=a[i];
    if(sum%2) return printf("NO"),0;
   for(int i=1;i<=n;i++){
   f[a[i]]=true;
   s+=a[i]; 
   if(s==sum/2) 
  return printf("YES"),0;
   if(i>1&&f[s-sum/2]) 
  return printf("YES"),0;
}
 s=0;
 f.clear();
   for(int i=n;i>=1;i--){
   f[a[i]]=true;
   s+=a[i]; 
   if(s==sum/2) 
  return printf("YES"),0;
   if(i<n&&f[s-sum/2]) 
  return printf("YES"),0;
}
   return printf("NO"),0;

}