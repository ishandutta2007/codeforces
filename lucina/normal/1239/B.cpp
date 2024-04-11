#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;

/**
    Consider prefix sum
    (               ) (              )
    if we swap (    with )
    (                   ) (                )
    L                                      R
    The result is -2 all prefix sum in range L - R
    If its level is > 2, no change
    So the left end should have level 1 or zero
    If it's zero
    (           ()   ()  ) (       )
    Consider if it's not swap with its match
    ( ( ) )  ( )
    ) ( ) )  ( (
    Answer is number of zero in that range and it cannot be greater than original answer
    (              )
    So the minimum is -1, answer is number of level 1
    If level of left end is 1
    ( ( ....) )
    swap sth before its match
    ( (  (....)  ) ) ()
    ( )  (....(  ) ) () minimum prefix sum is still = 0, didn't contribute more 0
    swap with sth later than its match
    ( (  (.....( ) ) ) )
    minimum prefix sum = -2 and equal to number of zero in that range
    So the answer is not greater
    so we should swap with its match
    (  (  )   (....) ( ) )
    (  (  )   )....( ( ) )
    will add number of inner bracket to original answer, so it's just two cases to consider
    swap ) with ( just increase all prefix sum in range and not increase answer
*/
int n;
char s[maxn];

int main(){
    scanf("%d %s", &n, s + 1);
    int num = 0;
    int bal = 0, start = 0, minbal = maxn;
    for(int i = 1 ; i <= n ;i++){
        num += s[i] == '(';
        bal += s[i] == '(' ? 1 : -1;
        if(bal < minbal){
            minbal = bal;
            start = i;
        }
    }
    if(n % 2 || (n % 2 == 0 && num != n / 2)) return !printf("0\n1 1");
    auto pos = [&](int i){
        return i > n  ? i-n : i;
    };
    bal = 0;
    ++start;
    fprintf(stderr, "start = %d\n", start);
    int ans = 0, l = 1 , r = 1;
    for(int i = start ; i <= start + n - 1 ; i++){
        bal += s[pos(i)] == '(' ? 1 : -1;
        if(bal < 0) return !printf("0\n1 1");
        if(bal == 0){
            ++ ans;
        }
    }
    int base = ans;
    if(bal > 0) return !printf("0\n1 1");
    vector<pair<int, int> > st;
    /*
    ()()())(()
    -> ( () () () () )
    ->
    */
    for(int i = start ;i <= start + n - 1 ; i ++){
      //  printf("%c",s[pos(i)]);
        if(s[pos(i)] == '('){
        if((int)st.size() > 0) ++st.back().second;
        st.push_back(make_pair(pos(i) , 0));
        }
        else{
            auto cur = st.back();
            st.pop_back();
            if((int) st.size() == 0){
              //  fprintf(stderr, "%d\n", cur.second);
                if(cur.second  + 1 > ans){
                    ans = cur.second + 1;
                    l = cur.first;
                    r = pos(i);
                }
            }
            else if((int)st.size() == 1 ){
                if(base + cur.second + 1 > ans){
                    ans = base + cur.second + 1;
                    l = cur.first;
                    r = pos(i);
                }
            }

        }
    }
    printf("%d\n%d %d", ans , l, r);
}