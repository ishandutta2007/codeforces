/*
30 10 10 1
1 10
3 20
1 -96967209
3 -90686725
2 -93246967
1 -22571678
2 15
2 -81266777
2 -53922501
3 -34959430
-4137910
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define fi first
#define se second
typedef pair <int, int> pii;
const int MAXN = 200005;

int gas1[MAXN], gas3[MAXN], next[MAXN], e, s, n, m;
pii gas[MAXN], cost[MAXN], temp;

pii merge(pii l, pii r){
    if(r.fi == -1 || l.fi == -1) return pii(-1, -1);
    return pii(l.fi + r.fi, l.se + r.se);
}
int main(){
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int i, l, r, mid, pos, st, end;
    scanf("%d%d%d%d", &e, &s, &n, &m);
    for(i = 1; i <= n; ++ i)
        scanf("%d%d", &gas[i].se, &gas[i].fi);
    ++ n;
    gas[n].fi = e, gas[n].se = 3;
    sort(gas + 1, gas + 1 + n);
    for(i = 1; i <= n; ++ i){
        gas1[i] = gas1[i - 1] + int(gas[i].se == 1);
        gas3[i] = gas3[i - 1] + int(gas[i].se == 3);
    }
    for(i = n; i; -- i){
        switch(gas[i].se){
            case 1:
                if(i == n || gas[i + 1].fi - gas[i].fi > s){
                    next[i] = 0;
                    cost[i].fi = cost[i].se = -1;
                    break;
                }
                if(gas[i + 1].fi - gas[i].fi > s){
                    next[i] = 0;
                    cost[i].fi = cost[i].se = -1;
                }else{
                    next[i] = i + 1;
                    cost[i].fi = gas[i + 1].fi - gas[i].fi;
                    cost[i].se = 0;
                    cost[i] = merge(cost[i], cost[i + 1]);
                }
                break;
            case 2:
                if(i == n || gas[i + 1].fi - gas[i].fi > s){
                    next[i] = 0;
                    cost[i].fi = cost[i].se = -1;
                    break;
                }
                l = i + 1, r = n;
                while(l < r){
                    mid = (l + r) >> 1;
                    if(gas1[mid] - gas1[i] == mid - i) l = mid + 1;
                    else r = mid;
                }
                if((gas[r].se == 1) || (gas[r].fi - gas[i].fi > s)){
                    l = i + 1, r = n;
                    while(l < r){
                        mid = (l + r + 1) >> 1;
                        if(gas[mid].fi - gas[i].fi > s) r = mid - 1;
                        else l = mid;
                    }
                    if(gas[r].fi - gas[i].fi > s || gas[r + 1].fi - gas[r].fi > s){
                        next[i] = 0;
                        cost[i].fi = cost[i].se = -1;
                    }else{
                        next[i] = r + 1;
                        cost[i].fi = gas[r + 1].fi - gas[i].fi - s;
                        cost[i].se = s;
                        cost[i] = merge(cost[i], cost[r + 1]);
                    }
                }else{
                    next[i] = r;
                    cost[i].fi = 0;
                    cost[i].se = gas[r].fi - gas[i].fi;
                    cost[i] = merge(cost[i], cost[r]);
                }
                break;
            case 3:
                if(gas[i].fi == e){
                    next[i] = cost[i].fi = cost[i].se = 0;
                    break;
                }
                if(gas[i + 1].fi - gas[i].fi > s){
                    next[i] = 0;
                    cost[i].fi = cost[i].se = -1;
                    break;
                }
                l = i + 1, r = n;
                while(l < r){
                    mid = (l + r) >> 1;
                    if(gas3[mid] - gas3[i] > 0) r = mid;
                    else l = mid + 1;
                }
                if((gas[r].se != 3) || (gas[r].fi - gas[i].fi > s)){
                    l = i + 1, r = n;
                    while(l < r){
                        mid = (l + r) >> 1;
                        if(gas[mid].fi > gas[i].fi + s) r = mid;
                        else l = mid + 1;
                    }
                    pos = r - int(gas[r].fi > gas[i].fi + s);
                    l = i + 1, r = pos;
                    while(l < r){
                        mid = (l + r + 1) >> 1;
                        if(gas1[pos] - gas1[mid - 1] == pos - mid + 1) r = mid - 1;
                        else l = mid;
                    }
                    if((gas[r].se != 2) || (next[r] && gas[next[r]].fi - gas[i].fi <= s)){
                        l = i + 1, r = n;
                        while(l < r){
                            mid = (l + r + 1) >> 1;
                            if(gas[mid].fi - gas[i].fi > s) r = mid - 1;
                            else l = mid;
                        }
                        if(gas[r].fi - gas[i].fi > s || gas[r + 1].fi - gas[r].fi > s){
                            next[i] = 0;
                            cost[i].fi = cost[i].se = -1;
                        }else{
                            next[i] = r + 1;
                            cost[i].fi = gas[r + 1].fi - gas[i].fi - s;
                            cost[i].se = 0;
                            cost[i] = merge(cost[i], cost[r + 1]);
                        }
                    }else{
                        if(cost[r].fi == -1){
                            cost[i].fi = cost[i].se = -1;
                            next[i] = 0;
                            break;
                        }
                        next[i] = next[r];
                        if(gas[next[r]].fi - s <= gas[r].fi){
                            cost[i].fi = 0;
                            cost[i].se = gas[next[r]].fi - gas[i].fi - s;
                            cost[i] = merge(cost[i], cost[next[i]]);
                        }else{
                            cost[i].fi = gas[next[r]].fi - s - gas[r].fi;
                            cost[i].se = gas[r].fi - gas[i].fi;
                            cost[i] = merge(cost[i], cost[next[i]]);
                        }
                    }
                }else{
                    next[i] = r;
                    cost[i].fi = cost[i].se = 0;
                    cost[i] = merge(cost[i], cost[r]);
                }
                break;
        }
        //printf("%d %d: %d %d\n", gas[i].fi, gas[i].se, cost[i].fi, cost[i].se);
    }
    for(i = 1; i <= m; ++ i){
        scanf("%d", &st);
        l = r = mid = pos = end = 0;
        l = 1, r = n;
        while(l < r){
            mid = (l + r) >> 1;
            if(gas[mid].fi >= st) r = mid;
            else l = mid + 1;
        }
        pos = r;
        if(gas[pos].fi - st > s){
            printf("-1 -1\n");
            continue;
        }
        l = pos, r = n;
        while(l < r){
            mid = (l + r) >> 1;
            if(gas3[mid] - gas3[pos - 1] > 0) r = mid;
            else l = mid + 1;
        }
        if((gas[r].se != 3) || (gas[r].fi - st > s)){
            //printf("3-station not found\n");
            l = pos, r = n;
            while(l < r){
                mid = (l + r) >> 1;
                if(gas[mid].fi > st + s) r = mid;
                else l = mid + 1;
            }
            end = r - int(gas[r].fi > st + s);
            //printf("end point = %d\n", end);
            l = pos, r = end;
            while(l < r){
                mid = (l + r + 1) >> 1;
                if(gas1[end] - gas1[mid - 1] != end - mid + 1) l = mid;
                else r = mid - 1;
            }
            if((gas[r].se != 2) || (next[r] && gas[next[r]].fi - st <= s)){
                //printf("2-station not found; target = %d\n", end + 1);
                if(gas[end + 1].fi - gas[end].fi > s) temp.fi = temp.se = -1;
                else{
                    temp.fi = gas[end + 1].fi - st - s;
                    temp.se = 0;
                    temp = merge(temp, cost[end + 1]);
                }
                //printf("%d %d\n", temp.fi, temp.se);
            }else{
                //printf("2-station found; target = %d\n", r);
                if(cost[r].fi == -1)
                    temp.fi = temp.se = -1;
                else{
                    temp.fi = cost[r].fi - cost[next[r]].fi;
                    temp.se = cost[r].se - cost[next[r]].se;
                    if(!temp.fi)
                        temp.se -= s - gas[r].fi + st;
                    else{
                        temp.fi = max(gas[next[r]].fi - gas[r].fi - s, 0);
                        temp.se = min(gas[next[r]].fi - st - s, gas[r].fi - st);
                    }
                    temp = merge(temp, cost[next[r]]);
                }
            }
            printf("%d %d\n", temp.fi, temp.se);
        }else printf("%d %d\n", cost[r].fi, cost[r].se);
    }
    return 0;
}