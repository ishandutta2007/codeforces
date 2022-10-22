#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100
#define MOD 1000000007

priority_queue<long long> utoku,pq;
pair<long long,long long> predstojece[MAXN];
int n;
long long x,y;
long long res;

void citaj(){
    cin>>n;
    cin>>x>>y;
    for(int i=0;i<n;i++){
        cin>>predstojece[i].first>>predstojece[i].second;
    }
    sort(predstojece,predstojece+n);
}
void radi(){
    int i=0;
    while(i<n){
        while(!utoku.empty() && (-utoku.top())<predstojece[i].first) {
            pq.push(-utoku.top());
            utoku.pop();
        }
        if(pq.empty() || (pq.top())>=predstojece[i].first){
            res+=x+y*(predstojece[i].second-predstojece[i].first);
            res%=MOD;
            utoku.push(-predstojece[i].second);
            i++;
            continue;
        }
        if(y*(-pq.top()+predstojece[i].first)<x){
            res+=y*(predstojece[i].second-pq.top());
            res%=MOD;
            pq.pop();
            utoku.push(-predstojece[i].second);
            i++;
        }else{
            pq.pop();
        }

    }
    cout<<res;
}
int main()
{
    citaj();
    radi();
    return 0;
}