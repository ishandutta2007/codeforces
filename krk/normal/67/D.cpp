#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1000001;

int n, pl[Maxn], seq[Maxn];
vector <int> res;

int main()
{
    int tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        pl[tmp] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        seq[pl[tmp]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (res.size() == 0 || res[res.size()-1] > seq[i]) {
                       res.push_back(seq[i]);
                       continue;
        }
        int l = 0, r = res.size()-1, mid, ans;
        while (l <= r) {
              mid = (l + r) / 2;
              if (seq[i] > res[mid]) {
                         ans = mid;
                         r = mid - 1;
              } else l = mid + 1;
        }
        res[ans] = seq[i];
    }
    printf("%d\n", res.size());
    return 0;
}