#include <iostream>

using namespace std;

int main()
{
    long n;
    cin >> n;
    long long numbers[n];
    long long sums[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) cin >> numbers[i];
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        sums[i] = sum;
    }
    if (sum%3 != 0)
        {
          cout << "0";
          return 0;
        }
    sum = sum/3;
    long cnt = 0;
    for(int i = 1; i < n-1; i++){
        if (sums[i] == 2*sum)
            {
                cnt++;
            }
    }
    long long answer = 0;
    for (int i = 0; i < n-2; i++){
      if (sums[i] == sum*2) if (i > 0) cnt--;
      if (sums[i] == sum) answer += cnt;
    }
    cout << answer;
    return 0;

}