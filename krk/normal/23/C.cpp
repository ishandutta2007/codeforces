#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200000;

typedef long long ll;

int t, n;
pair <pair <int, int>, int> box[Maxn];

int main()
{
    ll sum, cursum;
    scanf("%d", &t);
    while (t--) {
          scanf("%d", &n); n = 2*n - 1;
          sum = 0;
          for (int i = 0; i < n; i++) {
              scanf("%d %d", &box[i].first.first, &box[i].first.second);
              box[i].second = i + 1;
              sum += box[i].first.second;
          }
          sort(box, box + n);
          printf("YES\n");
          cursum = 0;
          for (int i = 0; i < n; i += 2)
             cursum += box[i].first.second;
          if (2LL * cursum >= sum)
             for (int i = 0; i < n; i += 2) {
                 if (i) printf(" ");
                 printf("%d", box[i].second);
             }
          else {
               for (int i = 1; i < n; i += 2)
                  printf("%d ", box[i].second);
               printf("%d", box[n-1].second);
          }
          printf("\n");
    }
    return 0;
}