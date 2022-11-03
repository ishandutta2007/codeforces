#include<iostream>
using namespace std;
void merge_(int *a,int l,int mid,int r) { int z=0,c[100000]; int p1=l,p2=mid; while(p1<mid && p2<r) { if(a[p1]>a[p2]) { c[z++]=a[p2++]; } else { c[z++]=a[p1++]; } } for(;p1<mid;p1++) { c[z++]=a[p1]; } for(;p2<r;p2++) { c[z++]=a[p2]; } for(int j=0;j<r+l && l<r ;j++) { a[l++]=c[j]; } } void mergesort(int *a,int l,int r) { if(r-l==1) return ; else { int mid=(r+l)/2; mergesort(a,l,mid); mergesort(a,mid,r); merge_(a,l,mid,r); } } int main() { int n,sum=0,t=1; cin>>n; 
int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
mergesort(a,0,n);
for (int i=0;i<n-1;i++)    
   {
       sum+=a[i];
        if(sum<=a[i+1] && a[i+1]!=0)
        t++;
        else
        {
            a[i+1]=0;
        }

        }    
    cout<<t;
    }