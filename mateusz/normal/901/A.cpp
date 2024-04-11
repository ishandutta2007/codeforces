#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int h;
int cnt[N], pref[N];

int main() {
    
    scanf("%d", &h);
    
    for (int i = 0; i <= h; i++) {
        scanf("%d", &cnt[i]);
    }
    
    bool perfect = true;
    pref[0] = cnt[0];
    for (int i = 1; i < h; i++) {
        pref[i] = pref[i - 1] + cnt[i];
        if (cnt[i] > 1 && cnt[i + 1] > 1) {
            perfect = false;
//             break;
        }
    }
    pref[h] = pref[h - 1] + cnt[h];
    
    if (perfect) {
        printf("perfect\n");
        return 0;
    }
    
    vector<int> seq, seq2;
    seq.push_back(0);
    seq2.push_back(0);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            seq.push_back(pref[i - 1]);
            seq2.push_back(pref[i - 1]);
        }
        if (cnt[i] > 1 && cnt[i - 1] > 1) {
            seq2.back()--;
        }
    }
    
    printf("ambiguous\n");
    for (int i = 0; i < seq.size(); i++) {
        printf("%d ", seq[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < seq2.size(); i++) {
        printf("%d ", seq2[i]);
    }
    
    return 0;
}