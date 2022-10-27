#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,s,k,m,a[maxn],f,c[maxn],d,ct[maxn],x,g,lct[maxn],supercount;
bool b[maxn];
vector<int> ans;

int main(){
    scanf("%d%d%d%d",&m,&k,&n,&s);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=s;i++){
        scanf("%d",&f);
        c[f]++;
        }
    int l=1,r=0;
    while(true){
        while(d!=s){
            r++;
            if(r>m){
                printf("-1");
                return 0;
            }
            if(c[a[r]]){
                    ct[a[r]]++;
                if(ct[a[r]]<=c[a[r]])
                    d++;
                }
        }
        while(r-l+1<k){
            r++;
            if(c[a[r]])
                ct[a[r]]++;
        }
       // cout<<l<<' '<<r<<endl;
        if((l-1)/k+(m-r)/k>=(n-1)){
           for(int i=l;i<=r;i++){
            if(c[a[i]]){
                if(lct[a[i]]<c[a[i]]){
                    lct[a[i]]++;
                    b[i]=true;
                }
            }
           }
           int fuck=l;
           while(g!=r-l+1-k){
                if(!b[fuck]){
                    g++;
                    ans.push_back(fuck);
                }
                fuck++;
           }
           g=(l-1)%k;
           for(int i=l-1;i>=1;i--){
            if(g==0)
                break;
            ans.push_back(i);
            g--;
           }
           printf("%d\n",ans.size());
           for(auto j:ans)
            printf("%d ",j);
           return 0;
        }
        else{
            if(c[a[l]]){
                ct[a[l]]--;
                if(ct[a[l]]<c[a[l]])
                    d--;
                    b[l]=false;
                }
            l++;
        }
    }
    }