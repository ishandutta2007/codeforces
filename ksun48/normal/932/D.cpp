#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXJ = 24;

LL jump[510000][MAXJ];
LL maxval[510000][MAXJ];

LL wgt[510000];
LL newjump[510000][MAXJ];
LL newsum[510000][MAXJ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL Q;
    cin >> Q;
    LL last = 0;
    LL cnt = 1;
    wgt[0] = 100000000000000000LL;
    wgt[1] = 0;
    for(int j = 0; j < MAXJ; j++){
        jump[0][j] = jump[1][j] = 0;
        maxval[0][j] = maxval[1][j] = wgt[0];

        newjump[0][j] = newjump[1][j] = 0;
        newsum[0][j] = newsum[1][j] = wgt[0];
    }
    for(int i = 0; i < Q; i++){
        LL t, p, q;
        cin >> t >> p >> q;
        LL R = p ^ last;
        LL X = q ^ last;
        //cout << "query " << R << " " << X << endl;
        if(t == 1){
            cnt++;
            wgt[cnt] = X;
            jump[cnt][0] = R;
            maxval[cnt][0] = wgt[R];
            for(int j = 1; j < MAXJ; j++){
                LL g = jump[cnt][j-1];
                jump[cnt][j] = jump[g][j-1];
                maxval[cnt][j] = max(maxval[cnt][j-1],
                 maxval[g][j-1]);
            }
            LL cur = cnt;
            for(int j = MAXJ-1; j >= 0; j--){
                if(maxval[cur][j] < wgt[cnt]){
                    cur = jump[cur][j];
                }
            }
            assert(cur != 0);
            cur = jump[cur][0];
            newjump[cnt][0] = cur;
            //cout << "make " << cnt << " " << cur << " " << wgt[cnt] << endl;
            newsum[cnt][0] = min(wgt[cur], wgt[0]);
            for(int j = 1; j < MAXJ; j++){
                LL g = newjump[cnt][j-1];
                newjump[cnt][j] = newjump[g][j-1];
                newsum[cnt][j] = newsum[cnt][j-1] + newsum[g][j-1];
                newsum[cnt][j] = min(newsum[cnt][j], wgt[0]);
            }
        } else {
            if(wgt[R] > X){
                last = 0;
                cout << 0 << '\n';
                continue;
            }
            LL num = 1;
            LL cur = R;
            X -= wgt[R];
            for(int j = MAXJ-1; j >= 0; j--){
                if(newsum[cur][j] <= X){
                    num += (1LL << j);
                    X -= newsum[cur][j];
                    cur = newjump[cur][j];
                }
            }
            last = num;
            cout << num << '\n';
            continue;
        }
    }
}