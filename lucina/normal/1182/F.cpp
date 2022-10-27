#include<bits/stdc++.h>
using namespace std;
 // #define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif
const int inf = 2e9+7;
int p,q,a,b;

int solve(){
    scanf("%d%d%d%d",&a, &b, &p, &q);
    int len = b-a+1;
    int del = inf,ans = -1;
    if(len <= 50000){
        for(int i=a;i<=b;i++){
            int cur = (2LL * p * i) % (2*q);
            cur = abs(cur - q);
            if(cur < del){
                ans = i;
                del = cur;
            }
        }
        return ans;
    }
    int block = (int)(sqrt(len)) ;
    vector<pair<int,int>> res;
    for(int i=0;i < block ; i++){
        res.push_back(make_pair((int)( (2LL * p * (a+i))% (2 *q)), a + i));
    }
    sort(res.begin(),res.end());
    vector<pair<int,int>> keep;
    for(int i = 0;i < (int) res.size() ; i++){
        int j = i;
        keep.push_back(res[i]);
        while( (j < (int)res.size()) && res[i].first == res[j].first)
         j++;
        i = j-1;
    }
    res = keep;
    int tar = q, toadd = (2LL * block * p) %(2 * q);
    int pt = a,now = 0;
    del = inf , ans = inf;
    while(b - pt + 1 >= block){
        int t = lower_bound(res.begin(),res.end(),make_pair(tar,-1)) - res.begin();
            if(abs(res[t].first - tar) < del){
                del = abs(res[t].first - tar);
                ans = res[t].second + now;
            }
            else if(abs(res[t].first-tar) == del){
                ans = min(ans, res[t].second + now);
            }
            t--;
            if (t < 0)
                t = (int) res.size() - 1;
            if(abs(res[t].first - tar) < del){
                del = abs(res[t].first - tar);
                ans = res[t].second + now;
            }
            else if(abs(res[t].first - tar) == del)
                ans = min(ans, res[t].second + now);
        now += block;
        pt += block;
        tar -= (toadd);
        tar %= (2 * q);
        if(tar < 0) tar += 2*q;
    }
    /// brute force the remaining range
    for(int i = pt ;i <= b; i++){
        int cur = (2LL * p * i) % (2 * q);
        cur = abs(cur - q);
        if(cur < del){
            del = cur;
            ans = i;
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t -- ){
        printf("%d\n",solve());
    }

}
/**

    Given p,q,a,b
    Find minimum x in range (a,b)
    such that |sin(p/q * pi * x)| is maximized
    Key point : |sin (V)| is maximized when it's closed to pi/2 or 3pi/2
    It means that ... -> Let X = p/q * x
    if(X - floor(X)) is closed to 1/2
    let px mod q = c then we want c to be closed to q / 2
    px mod q =~ q/2 -> 2px mod 2q =~ q
    Then next key idea is to split range it to square root range
    And calculate g(x) = 2px mod (2q) in such range
    Then we can basically do binary search to find what is the closet to q
    target = q, but when we jump into next block, we can simply use the data from last block
    Everything is += g(block) If it's closed to q in the next block, it means it closed to q - g(block) in the last block


*/