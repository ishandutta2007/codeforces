#include <bits/stdc++.h>
using namespace std;




int n, k;


int data[256];
int borders[256];

vector<int> sequence;



int main()
    {

    int tmp = -1;
    cin >> n >> k;

    sequence.resize(n);

    for (int i = 0; i < 256; i++)
        borders[i] = -1;

    for (size_t i = 0; i < n; i++)
        {
        cin >> sequence[i];
        //data[sequence[i]]++;
        }

    for (int i = 0; i < n; i++)
        {
        if (borders[sequence[i]] == -1)
            {
            int j = sequence[i];

            int MINIM = max(0, j - k + 1);
            while (true)
                {
                if (borders[j] == -1)
                    {
                    if (j == MINIM) break;
                    else
                        {
                        j--;
                        continue;
                        }
                    }
                else
                    {
                    if (borders[j] + k - 1 >= sequence[i])
                        {
                        j = borders[j];
                        break;
                        }
                    else
                        {
                        j++;
                        break;
                        }
                    }
                }

            tmp = j;
            for (; j <= sequence[i]; j++)
                borders[j] = tmp;
            }
        }

    for (int i = 0; i < n; i++)
        cout << borders[sequence[i]] << " ";

    }