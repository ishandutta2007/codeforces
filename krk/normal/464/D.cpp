#include <cstdio>
using namespace std;

const int Maxn = 100005;
const int Maxm = 550;
const double eps = 1e-15;

int n, k;
double mult[Maxm];
double prob[Maxm];
double res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i < Maxm; i++)
        mult[i] = (k - 1 + double(i) / (i + 1)) / k; 
    prob[1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = Maxm - 2; j > 0; j--) if (prob[j] > eps) {
            res += prob[j] * j / 2;
            double pr = prob[j] / (j + 1);
            res += pr * j;
            prob[j] = prob[j] * mult[j];
            prob[j + 1] += pr / k;
        }
    printf("%.15lf\n", res);
    return 0;
}