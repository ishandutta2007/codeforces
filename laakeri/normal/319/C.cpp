#include <iostream>
#include <queue>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll a[100001];
ll b[100001];

ll dp[100001];

ll cost(int c, int i){
    return dp[c]+a[i]*b[c];
}

int n;

int bt(int a, int b, int i){//milloin b on parempi kuin a
    int mi=i;
    int ma=n-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (cost(b, m)<=cost(a, m)){
            ma=m-1;
        }
        else{
            mi=m+1;
        }
    }
    return mi;
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    deque<pair<int, int> > op;
    op.push_back({0, 0});//mik i, ensimminen indexi jossa on paras vaihtoehto
    for (int i=1;i<n;i++){
        while (op.size()>1&&op[1].S<=i){
            op.pop_front();
        }
        dp[i]=cost(op[0].F, i);

        if (i<n-1){
            if (op.front().S<=i) op.front().S=i+1;
            while (op.size()>0&&cost(i, op.back().S)<=cost(op.back().F, op.back().S)){
                op.pop_back();
            }
            if (op.size()>0){
                int k=bt(op.back().F, i, op.back().S);
                if (k<n) op.push_back({i, k});
            }
            else{
                op.push_back({i, i+1});
            }
        }
    }
    cout<<dp[n-1]<<endl;
}