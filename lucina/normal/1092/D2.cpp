#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
stack<int> fuck;
int n,a[maxn],max1;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        max1=max(max1,a[i]);
    }
    for(int i=1;i<=n;i++){
            if(!fuck.empty()){
                if(a[i]==fuck.top()){
                    fuck.pop();
                    if(!fuck.empty()){
                    if(fuck.top()<a[i]){
                        printf("NO\n");
                        return 0;
                    }
                    }
                    continue;
                }
            }
            fuck.push(a[i]);
            }


    if(fuck.size()==0){
        printf("YES\n");
    }
    else if(fuck.size()==1&&fuck.top()==max1){
        printf("YES\n");
    }
    else
        printf("NO\n");
    }