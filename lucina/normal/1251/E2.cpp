#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n,m ,p;
vector<int> a[maxn];


int main(){
    int T;
    for(cin >> T ; T -- ;){
    scanf("%d", &n);
    for(int i = 1 ;i <= n;i ++){
        scanf("%d %d", &m, &p);
        a[m].push_back(p);
    }
    ///greedy backward
    int t = n, cnt = 0;
    long long cost = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = n -1 ;i >= 0 ; i--){
        t -= (int)a[i].size();
        for(int j:a[i])
            q.push(j);
        //if  pref + cnt >= i we have no need to buy at this spot
        /// pref + cnt < i -> cnt < i - pref
        /// i - pref - cnt
        /// summation from a[i] to a[n] >= i - pref?
        /// obviously because a[i] + pref = n >= i
        /// so guarantee heap size
        int toadd = i - t;
        while(cnt < toadd){
            cnt++;
            cost += q.top();
            q.pop();
        }
    }
    printf("%lld\n", cost);
    for(int i = 0;i<= n;i++){
        a[i].clear();
    }

    }
}