#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int x,q,n,k;

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&n,&k);
       /// n=rand()%10+1;k=(rand()%n)+1;
     ///   cerr<<n<<' '<<k<<'\n';
        vector<int> odd;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
          // x=rand();
          // cerr<<x%2<<' ';
            if(x%2){
                odd.push_back(i);
            }
        }
       /// cerr<<'\n';
        if((int)odd.size()<k){
            printf("NO\n");
            continue;
        }
        reverse(odd.begin(),odd.end());
        int need=(int)(odd.size())-k;
        if(need&1){
            printf("NO\n");
            continue;
        }
        while(need--)
            odd.pop_back();
        reverse(odd.begin(),odd.end());
        odd.back()=n;
        assert((int)odd.size()==k);
        printf("YES\n");
        for(int i:odd){
            printf("%d ",i);
        }
        printf("\n");
    }
}
/*
    Good Luck
        -Lucina
*/