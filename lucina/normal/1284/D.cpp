#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
struct event{
    int la, ra, lb, rb;
    event(){}
    void read(){
        scanf("%d %d %d %d", &la, &ra, &lb, &rb);
    }
    void sw(){
        swap(la, lb);
        swap(ra, rb);
    }
    bool operator < (const event & x) const{
        return la < x.la;
    }
};
bool cmp(const event & x, const event & y){
    return x.ra < y.ra;
}
int n;
event e[nax], b[nax];
vector<int> all;
void no(){
    printf("NO\n");
    exit(0);
}
 
struct fenwick{
    static const int mx = nax * 6;
    int bit[mx];
    int get(int idx){
        int res = 0;
        for(; idx > 0; idx ^= idx & - idx)
            res += bit[idx];
        return res;
    }
    void update(int idx, int val){
        for(; idx < mx ; idx += idx & -idx)
            bit[idx] += val;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
    void clean(){
        fill(bit, bit + mx, 0) ;
    }
};
fenwick f, g;
 
int main(){
    scanf("%d", &n);
    all.emplace_back(0);
    for(int i = 1 ;i <= n; i++){
        e[i].read();
        all.emplace_back(e[i].la);
        all.emplace_back(e[i].ra);
        all.emplace_back(e[i].lb);
        all.emplace_back(e[i].rb);
        all.emplace_back(e[i].ra + 1);
        all.emplace_back(e[i].rb + 1);
        b[i] = e[i];
    }
    sort(e + 1, e + 1 + n, cmp);
    sort(b + 1, b + 1 + n);
    sort(all.begin() + 1 , all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    auto id = [&] (int x){
        return (int)(lower_bound(all.begin(), all.end(), x) - all.begin());
    };
    /**
    e sorted by r
    b sorted by l
    */
    auto test = [&](){
        for(int i = 1; i <= n ;i ++){
            f.update(id(b[i].lb), 1);
            f.update(id(b[i].rb), 1);  
            g.update(id(b[i].lb), 1);
            g.update(id(b[i].rb + 1), -1);
        }
        int pt = 1;
        for(int i = 1 ;i <= n; i ++){
            while(pt <= n && b[pt].la <= e[i].ra){
                f.update(id(b[pt].lb), -1);
                f.update(id(b[pt].rb), -1);
                g.update(id(b[pt].lb), -1);
                g.update(id(b[pt].rb + 1), 1);
                pt ++ ;
            }
            if((f.get(id(e[i].lb), id(e[i].rb))) > 0){
                no();
            }
           if(g.get(id(e[i].lb)) > 0)
                no();
          }
        return ;
    };
    test();
    for(int i = 1 ;i <= n; i++){
        b[i].sw();
        e[i].sw();
    }
    sort(e + 1 , e + 1 + n, cmp);
    sort(b + 1, b + 1 + n);
    f.clean(); 
    g.clean();
    test();
    printf("YES\n");
}