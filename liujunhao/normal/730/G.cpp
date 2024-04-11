#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200;
typedef long long LL;
LL s[MAXN+10], d[MAXN+10], ed[MAXN+10], st[MAXN+10];
set<pair<LL, int> > sts;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d", &s[i], &d[i]);
        int cnt=0, ep = s[i]+d[i]-1;
        for(int j=1;j<i;j++)
            if(ed[j] < s[i])
                cnt++;
        for(int j=1;j<i;j++)
            if(st[j] > ep)
                cnt++;
        if(cnt == i-1){
            st[i] = s[i], ed[i] = ep;
            sts.insert(make_pair(st[i], i));
        }else{
            LL pos = 1;
            while(true){
                set<pair<LL, int> >::iterator iter = sts.lower_bound(make_pair(pos, -1));
                if(iter == sts.end()){
                    st[i] = pos, ed[i] = pos+d[i]-1;
                    sts.insert(make_pair(st[i], i));
                    break;
                }else{
                    if((*iter).first-pos > d[i]){
                        st[i] = pos, ed[i] = pos+d[i]-1;
                        sts.insert(make_pair(st[i], i));
                        break;
                    }else{
                        pos = ed[(*iter).second]+1;
                        continue;
                    }
                }
            }
        }
        printf("%I64d %I64d\n", st[i], ed[i]);
    }

    return 0;
}