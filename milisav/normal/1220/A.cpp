    #include<bits/stdc++.h>
    #define maxn 1000000
    using namespace std;
    char s[maxn];
    int n;
    int main() {
        scanf("%d",&n);
        int z=0;
        int o=0;
        scanf("%s",s);
        for(int i=0;i<n;i++) {
            if(s[i]=='z') z++;
            if(s[i]=='n') o++; 
        }
        for(int i=0;i<o;i++) printf("1 ");
        for(int i=0;i<z;i++) printf("0 ");
        return 0;
    }