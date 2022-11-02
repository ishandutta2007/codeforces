#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int mod=1e9+7;
int ans=0;
void dfs(int pos,int sum){

}
int main(){
    int n;
    char s[100001];
    map<char,int>M;
    M['A']=0,M['C']=1,M['G']=2,M['T']=3;
    scanf("%d%s",&n,s);
    int cnt[4]={0};
    for(int i=0;i<n;i++){
        int idx=M[s[i]];
        cnt[idx]++;
    }
    sort(cnt,cnt+4);
    int mac=0;
    for(int i=3;i>=0;i--){
        if(cnt[i]==cnt[3])mac++;
    }
    long long ans=1;
    for(int i=0;i<n;i++){
        ans*=mac;
        ans%=mod;
    }
    printf("%d\n",ans);

    return 0;
}