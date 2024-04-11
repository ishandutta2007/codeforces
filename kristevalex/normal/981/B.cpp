#include <bits/stdc++.h>
using namespace std;



struct mstr
    {
    long price, num;

    operator< (mstr over)
        {
        return num < over.num;
        }
    };

vector<mstr> company1, company2;

int num1, num2;


int main()
    {
    cin >> num1;

    company1.resize(num1);

    for (int i = 0; i < num1; i++)
        {
        cin >> company1[i].num >> company1[i].price;
        }

    cin >> num2;
    company2.resize(num2);

    for (int i = 0; i < num2; i++)
        {
        cin >> company2[i].num >> company2[i].price;
        }

    sort(company1.begin(), company1.end());
    sort(company2.begin(), company2.end());

    long long sum = 0;

    long i = 0, j = 0;


    while (true)
        {
        if (i >= num1 && j >=num2) break;
        if (i >= num1)
            {
            sum+= company2[j].price;
            j++;
            continue;
            }
        if (j >= num2)
            {
            sum+= company1[i].price;
            i++;
            continue;
            }
        if (company1[i].num == company2[j].num)
            {
            sum+= max(company1[i].price, company2[j].price);
            i++;
            j++;
            continue;
            }
        if (company1[i].num < company2[j].num)
            {
            sum+= company1[i].price;
            i++;
            continue;
            }
        if (company1[i].num > company2[j].num)
            {
            sum+= company2[j].price;
            j++;
            continue;
            }
        }





    cout << sum;



    return 0;
    }