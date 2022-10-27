#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
struct seg{
    int l, r, id;
    bool operator <(const seg &x) const{
        return r < x.r;
    }
    void read(int _id){
        this->id = _id;
        scanf("%d %d", &l,&r);
    }
};
priority_queue<seg> q;
int n, k, mr;
int pre[maxn];
vector<seg> a[maxn];
vector<int> ans;

int main(){
    scanf("%d %d", &n, &k);
    //a.resize(n);
    for(int i = 1 ;i<= n ;i++){
        seg v;
        v.read(i);
        a[v.l].push_back(v);
        mr = max(mr, v.r);
    }
  //  cout << "mr = " << mr << endl;
    for(int i = 1 ;i<= mr;i++){
        pre[i] += pre[i - 1];
     //   if(i >= 7)
      //  fprintf(stderr, " %d %d\n", i , pre[i]);
        for(auto j:a[i]){
            pre[i] ++;
            pre[j.r + 1] --;
            q.push(j);
        }

        while(pre[i] > k){
            assert(!q.empty());
            auto top = q.top();
            q.pop();
            pre[top.r + 1] ++;
            pre[i] --;
            ans.push_back(top.id);
        }
     //   if(i == 8)
        //cout <<"wat " << pre[9] << ' ' <<pre[8] << endl;
    }
    sort(ans.begin() , ans.end());
    printf("%d\n",(int)ans.size());
    for(int i:ans){
        printf("%d ",i);
    }

}