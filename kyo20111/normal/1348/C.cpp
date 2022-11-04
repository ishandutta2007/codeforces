#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, k, chk[300];
char s[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",s+1);
        sort(s+1, s+1+n);


        if(s[1] != s[k]){
            printf("%c\n",s[k]);
            continue;
        }
        for(int i='a';i<='z';i++) chk[i] = 0;
        for(int i=1;i<=n;i++) chk[s[i]]++;

        vector<int> v;
        for(int i='a';i<='z';i++) if(chk[i]) v.push_back(i);

        if(v.size() > 2){
            printf("%s\n",s+k);
            continue;
        }

        if(v.size() == 2 && chk[v[0]] > k){
            printf("%s\n",s+k);
            continue;
        }

        if(v.size() == 2){
            printf("%c",v[0]);
            for(int i=1;i<=chk[v[1]]/k+(chk[v[1]]%k?1:0);i++) printf("%c",v[1]);
            puts("");
        }
        else{
            for(int i=1;i<=chk[v[0]]/k+(chk[v[0]]%k?1:0);i++) printf("%c",v[0]);
            puts("");
        }
    }
}