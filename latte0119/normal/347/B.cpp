#include<bits/stdc++.h>
using namespace std;

int a[100000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<n;i++)if(a[i]==i)cnt++;
    int ma=0;
    for(int i=0;i<n;i++){
        if(a[i]!=i){
            if(a[a[i]]==i)ma=max(ma,2);
            else ma=max(ma,1);
        }
    }
    cout<<cnt+ma<<endl;

    return 0;
}