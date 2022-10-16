#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct ten{
    int tot[10];

    ten(){
        memset(tot, 0, sizeof tot);
    }

    ten operator +(ten a){
        ten ans;
        for (int i = 0; i < 10; ++i)
            ans.tot[i] = tot[i] + a.tot[i];
        return ans;
    }

    ten operator -(ten a){
        ten ans;
        for (int i = 0; i < 10; ++i)
            ans.tot[i] = tot[i] - a.tot[i];
        return ans;
    }

    bool positive(){
        for (int i = 0;i < 10; ++i)
            if (tot[i] < 0) return false;
        return true;
    }

    int sum(){
        int ans = 0;
        for (int i = 0;  i < 10; ++i)
            ans += tot[i];
        return ans;
    }

    int min(int a = -1){
        for (int i = a + 1; i < 10; ++i)
            if (tot[i]) return i;
        return 100;
    }
};

ten digits(int n){
    ten ans;

    if (n == 0){
        ans.tot[0]++;
    }
    else{
        while (n){
            ans.tot[n % 10]++;
            n /= 10;
        }
    }
    return ans;
}

ten digits(string s){
    ten ans;
    for (auto c : s)
        ans.tot[c - '0']++;
    return ans;
}

int main()
{
#ifdef HOME
    assert(freopen("input.in", "r", stdin));
    // assert(freopen("output.out", "w", stdout));
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, k;
    cin >> s >> k;

    if (k == "0" && (s == "01" || s == "10")){
        cout << 0 << endl;
        exit(0);
    }

    int pnt = 0;
    while (pnt < (int)k.length() && k[pnt]==k[0])++pnt;
    int value = pnt==(int)k.length() ? 10 : k[pnt] - '0';
    bool okk = value < k[0] - '0';

    int tzeros = 0;
    for (int i = 1; i < (int)k.length() && k[i] == '0'; ++i)
        ++tzeros;

    ten ds = digits(s);
    ten dk = digits(k);
    ten diff = ds - dk;

    for (int d = 1; ;++d){
        ten dd = digits(d);
        ten dcur = diff - dd;
        if (dcur.positive() && (ds - dd).sum() == d){
            if (k[0] != '0' && dcur.sum() == 0){
                cout << k << endl;
                exit(0);
            }

            if (k[0] != '0' || dcur.tot[0] < dcur.sum()){
                // cout << d << endl;
                int value = dcur.min(0);
                bool putk = false;

                if (value < k[0] - '0' || k[0] == '0'){
                    cout << value;
                    dcur.tot[value]--;
                }
                else if (value == k[0] - '0'){
                    if (okk && (tzeros > dcur.tot[0] || tzeros + 1 == (int)k.length() || (tzeros == 0 && dcur.tot[0] == 0)))
                    {
                        cout << k;
                        putk = true;
                    }
                    else{
                        cout << value;
                        dcur.tot[value]--;
                    }
                }
                else{
                    cout << k;
                    putk = true;
                }

                for (int i = 0;  i < 10; ++i){
                    if (i == k[0] - '0' && !putk){
                        if (okk){
                            cout << k;
                            for (int j = 0; j < dcur.tot[i]; ++j)
                                cout << i;
                        }
                        else{
                            for (int j = 0; j < dcur.tot[i]; ++j)
                                cout << i;
                            cout << k;
                        }
                    }
                    else{
                        for (int j = 0; j < dcur.tot[i]; ++j)
                            cout << i;
                    }
                }

                cout << endl;
                exit(0);
            }
        }
    }

    return 0;
}