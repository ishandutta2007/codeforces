#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL M = 10004205361450474;
const LL MAXK = 10000;
const LL Q0 = 0;
const LL Q1 = MAXK + (MAXK + 1) * Q0;
const LL Q2 = MAXK + (MAXK + 1) * Q1;
const LL Q3 = MAXK + (MAXK + 1) * Q2;
const LL Q4 = MAXK + (MAXK + 1) * Q3;
const LL Q5 = M;

vector<LL> nothing;

bool canwin(LL queries_left, LL a, LL b, LL find_flag = 0, vector<LL>& what_to_guess = nothing){
    //if(queries_left >= 4) cout << "try " << queries_left << " " << a << " " << b << endl;
    if(a > b) return 1; // done
    if(queries_left == 0) return 0;
    LL k = min(10000LL, a); // how many are you allowed to guess
    LL len = b - a + 1;
    LL max_len;
    LL prev;
    if(queries_left == 1){
        max_len = Q1; prev = Q0;
    }
    if(queries_left == 2){
        max_len = Q2; prev = Q1;
    }
    if(queries_left == 3){
        max_len = Q3; prev = Q2;
    }
    if(queries_left == 4){
        max_len = Q4; prev = Q3;
    }
    if(queries_left == 5){
        max_len = Q5; prev = Q4;
    }
    if(len > max_len) return 0;
    if(k == 10000){
        if(find_flag){
            for(LL r = 0; r < k; r++){
                LL d = a + prev + (prev + 1) * r;
                if(d <= b){
                    what_to_guess.push_back(d);
                } else {
                    break;
                }
            }
        }
        return 1;
    }
    // k < 10000
    vector<LL> guesses;
    LL cur_start = a;
    for(int i = 0; i < k; i++){
        if(cur_start > b) break;
        LL s_guess = cur_start; // can always win 
        LL e_guess = b + 1;
        // hijack this
        if(queries_left == 5){
            s_guess = 204761410474LL;
            e_guess = 204761410475LL;
        }
        while(s_guess + 1 < e_guess){
            LL m_guess = (s_guess + e_guess) / 2;
            if(canwin(queries_left - 1, cur_start, m_guess - 1)){
                s_guess = m_guess;
            } else {
                e_guess = m_guess;
            }
        }
        guesses.push_back(s_guess);
        cur_start = s_guess + 1;
    }
    if(canwin(queries_left - 1, cur_start, b)){
        // works
        if(find_flag){
            what_to_guess = guesses;
        }
        return 1;
    } else {
        return 0;
    }
}

int main(){
    LL queries_left = 5;
    LL a = 1;
    LL b = M;
    //assert(canwin(5, 1, M) == 1);
    while(1){
        vector<LL> what_do;
        assert(canwin(queries_left, a, b, 1, what_do)); // there's still hope!
        cout << what_do.size() << " ";
        for(int i = 0; i < what_do.size(); i++){
            cout << what_do[i] << " ";
        }
        cout << endl;
        LL res;
        cin >> res;
        if(res == -2) return 0;
        if(res == -1) return 0;
        if(res < what_do.size()){
            b = what_do[res] - 1;
        }
        if(res > 0){
            a = what_do[res - 1] + 1;
        }
        queries_left--;
    }
}