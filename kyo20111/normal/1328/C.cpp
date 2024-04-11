#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
char s[50050], a[50050], b[50050];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        a[1] = b[1] = '1';
        int fl = 0;
        for(int i=2;i<=n;i++){
            if(s[i] == '0') a[i] = b[i] = '0';
            if(s[i] == '1'){
                if(fl) b[i] = '1', a[i] = '0';
                else a[i] = '1', b[i] = '0', fl = 1;
            }
            if(s[i] == '2'){
                if(fl) b[i] = '2', a[i] = '0';
                else a[i] = '1', b[i] = '1';
            }
        }
        a[n+1] = b[n+1] = 0;
        printf("%s\n%s\n",a+1,b+1);
    }
}