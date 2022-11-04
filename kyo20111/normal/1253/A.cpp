#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[101010],b[101010];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=1;i<=n;i++) scanf("%d",b+i);
        int fl = 0, fl2 = 0, fl3 = 0;
        for(int i=1;i<=n;i++){
            if(a[i] != b[i]){
                if(a[i] > b[i] || (fl && fl3!=i-1)){
                    fl2 = 1;
                    break;
                }

                fl3 = i;
                int k = b[i] - a[i];

                if(!fl){
                    fl = k;
                    continue;
                }

                if(fl != k){
                    fl2 = 1;
                    break;
                }
            }
        }
        printf("%s\n",fl2?"NO":"YES");
    }
}