#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, d1[500500], d2[500500];
int s[10010010];
int main(){
    for(int i=2;i<=10000000;i++){
        if(s[i]) continue;
        s[i] = i;
        for(int j=i+i;j<=10000000;j+=i) s[j] = i;
    }

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        d1[i] = -1, d2[i] = -1;
        vector<int> v;
        int k = a;
        while(a != 1){
            if(v.empty() || v.back() != s[a]) v.push_back(s[a]);
            a /= s[a];
        }

        if(v.size() == 1) continue;

        int g = 1;
        for(int j=0;j<v.size()-1;j++) g *= v[j];
        d1[i] = g, d2[i] = v.back();
    }

    for(int i=1;i<=n;i++) printf("%d ",d1[i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%d ",d2[i]);
    puts("");
}