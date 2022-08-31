#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


string bad;
void cmp(string &a, string b){
    if(b.size() < a.size() || (b.size() == a.size() && b < a)){
        a = b;
    }
}

int main(){
    for(int i = 0; i < 500; i++) bad += 'X';
    string best[256][3];
    for(int i = 0; i < 256; i++){
        best[i][0] = best[i][1] = best[i][2] = bad;
    }
    best[15][0] = "x";
    best[51][0] = "y";
    best[85][0] = "z";
    int num = 3*256;
    for(int len = 1; len < 1000; len++){
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 3; j++){
                if(best[i][j].size() < bad.size()) continue;
                if(best[i][j].size() != bad.size()){
                    //cout << best[i][j] << " " << len << endl;
                    assert(best[i][j].size() <= len);
                }
                if(j == 0){
                    if((int)best[255 & (~i)][0].size() == len-1){
                        string str = "!" + best[255 & (~i)][0];
                        cmp(best[i][0], str);
                    }
                    if((int)best[i][2].size() == len-2){
                        string str = "(" + best[i][2] + ")";
                        cmp(best[i][0], str);
                    }
                } else if(j == 1){
                    if(best[i][0].size() == len){
                        cmp(best[i][1], best[i][0]);
                    }
                    for(int r = 0; r < 256; r++){
                        for(int s = 0; s < 256; s++){
                            if((r & s) == i){
                                if(((int)best[r][1].size() + (int)best[s][0].size() + 1) == len){
                                    string str = best[r][1] + "&" + best[s][0];
                                    cmp(best[i][1], str);
                                }
                            }
                        }
                    }
                } else if(j == 2){
                    if(best[i][1].size() == len){
                        cmp(best[i][2], best[i][1]);
                    }
                    for(int r = 0; r < 256; r++){
                        for(int s = 0; s < 256; s++){
                            if((r | s) == i){
                                if(((int)best[r][2].size() + (int)best[s][1].size() + 1) == len){
                                    string str = best[r][2] + "|" + best[s][1];
                                    cmp(best[i][2], str);
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 3; j++){
                if(best[i][j].size() == len){
                    num--;
                }
            }
        }
        if(num == 0) break;
    }
    for(int j = 0; j < 256; j++){
        string f;
        int r = j;
        for(int i = 0; i < 8; i++){ 
            f += (char)('0'+(r % 2));
            r /= 2;
        }
        reverse(f.begin(), f.end());
        string gg = bad;
        cmp(gg, best[j][0]);
        cmp(gg, best[j][1]);
        cmp(gg, best[j][2]);
        //cout << "ans[\"" << f << "\"] = \"" << gg << "\";\n";
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string g;
        cin >> g;
        int bnum = 0;
        for(int c = 0; c < 8; c++){
            bnum *= 2;
            bnum += g[c]-'0';
        }
        cout << best[bnum][2] << '\n';
    }
}