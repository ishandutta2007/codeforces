#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL

int n,a[maxn],t;
char s[maxn];
bool col[maxn];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;i++){
            a[i] = s[i] - '0';
        }
        vector<int> st1,st2;
        int idx = 1;
        while(a[idx]>=a[idx-1] && idx<=n){
            st1.push_back(idx++);
        }
        eprintf("idx = %d\n",idx);
        if(idx > n){
            for(int i=1;i<=n;i++){
                printf("1");
            }
            printf("\n");
            continue;
        }
        while(!st1.empty() && a[st1.back()] > a[idx]){
            st2.push_back(st1.back());
            st1.pop_back();
        }
        st1.push_back(idx);
        for(int i:st1)
            eprintf("%d",i);
        eprintf("\n");
        for(int i:st2)
            eprintf("%d",i);
        eprintf("\n");
        reverse(st2.begin(),st2.end());
        bool flag = true;
        for(int j=idx+1;j<=n;j++){
            if(a[j] >= a[st2.back()]){
                st2.push_back(j);
            }
            else if(a[j]<=a[st2[0]] && a[j]>=a[st1.back()]){
                st1.push_back(j);
                continue;
            }
            else{
                printf("-\n");
                flag = false;
                break;
            }
        }
        for(int i:st1){
            eprintf("%d ",a[i]);
            col[i] = 0;
        }
        eprintf("\n");
        for(int i:st2){
            col[i] = 1 ;
            eprintf("%d ",a[i]);
        }
        eprintf("\n");
        if(flag){
        for(int i=1;i<=n;i++){
            printf("%d",col[i]+1);
        }
        printf("\n");
        }
    }
}
/*
    Good Luck
        -Lucina
*/