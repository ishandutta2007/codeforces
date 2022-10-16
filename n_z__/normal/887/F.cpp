#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    cin>>a[x];
	int m=1,l=0,q=0;
    bool bo=false;
    for(int x=2;x<=n;x++)
    {
        if(a[x]<a[m])m=x,l=0;
        else{
            l++;
            if(l>=k){
                if(bo)return puts("NO"),0;
                bo=true;
                for(int y=m+1;y<=n;y++)
                if(a[m]>a[y]&&a[y]>a[q])q=y;
                if(q==0)return puts("NO"),0;
                swap(a[m+k],a[q]);
                m+=k;
                l=0;
            }
        }
    }
	puts("YES");
}