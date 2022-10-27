#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
char s[22];
char ss[22];
int n;
bool p[30],q[30];

int main(){
    scanf("%s%d",s,&n);
    for(int i=1;i<=n;i++){
        scanf("%s",ss);
        if((ss[0] == s[0]) && (ss[1] == s[1]))
            return !printf("YES\n");
        p[ss[0] - 'a'] = true;
        q[ss[1] - 'a'] = true;
    }
    if((q[s[0] - 'a'] && p[s[1] - 'a'] ))
        return !printf("YES\n");
    printf("NO\n");
}