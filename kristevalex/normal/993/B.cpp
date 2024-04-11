#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)




vector<vector<int>> matrix(9, vector<int> (9, 0));

int n, m, tmp1, tmp2;


int main()
    {
    FAST;

    cin >> n >> m;



    for (int i = 0; i < n; i++)
        {
        cin >> tmp1 >> tmp2;
        matrix[--tmp1][--tmp2]+= 1;
        matrix[tmp2][tmp1]+= 1;
        }

    for (int i = 0; i < m; i++)
        {
        cin >> tmp1 >> tmp2;
        matrix[--tmp1][--tmp2]+= 2;
        matrix[tmp2][tmp1]+= 2;
        }

    /*for (int i = 0; i < 9; i++)
        {
        for (int j = 0; j < 9; j++)
            {
            cout << " " << matrix[i][j];
            }
        cout << endl;
        } */


    bool can_I = true, can_THEM = true, WAS_I = false;
    int anser_I = -100;


    for (int i = 0; i < 9; i++)
        {
        int num1 = 0, num2 = 0, num_same = 0;
        for (int j = 0; j < 9; j++)
            {
            if (i == j) continue;

            if (matrix[i][j] == 1) num1++;
            if (matrix[i][j] == 2) num2++;
            if (matrix[i][j] == 3)
                {
                num1++;
                num2++;
                num_same++;
                }
            }
//if (i == 3) cout << "ywdcqk " << i  << " " << num1 << " " << num2 << " " << num_same << endl;

        if (num1 == 0 || num2 == 0 || (num1 == 1 && num2 == 1 && num_same == 1)) continue;
        if (/*(num1 == 1 && num2 == 1 && num_same == 0) || (num1+num2 == 3 && num_same == 1) || (num1 == 2 && num2 == 2 && num_same == 2)*/true)
            {
            //cout << i;
            //cout << false;
            if (!WAS_I)
                {
                WAS_I = true;
                anser_I = i;
                }
            else {can_I = false;}
            continue;
            }



        //can_I = false;
        //can_THEM = false;
        //break;
        }

    if (can_I)
        {
        cout << ++anser_I;
        return 0;
        }



    for (int i = 0; i < 9; i++)
        {
        for (int j = 0; j < 9; j++)
            {
            bool was1 = false, was2 = false;
            if (matrix[i][j] & 1)
                {
                for (int k = 0; k < 9; k++)
                    {
                    if (k == i || k == j) continue;
                    if (matrix[i][k] & 2)
                        {
                        if (!was1)
                            was1 = true;
                        }
                    }
                for (int k = 0; k < 9; k++)
                    {
                    if (k == i || k == j) continue;
                    if (matrix[j][k] & 2)
                        {
                        if (was1)
                            {
                            cout << -1;
                            return 0;
                            }
                        }
                    }
                }

            if (matrix[i][j] & 2)
                {
                for (int k = 0; k < 9; k++)
                    {
                    if (k == i || k == j) continue;
                    if (matrix[i][k] & 1)
                        {
                        if (!was2)
                            was2 = true;
                        }
                    }
                for (int k = 0; k < 9; k++)
                    {
                    if (k == i || k == j) continue;
                    if (matrix[k][j] & 1)
                        {
                        if (was2)
                            {
                            cout << -1;
                            return 0;
                            }
                        }
                    }
                }
            }
        }

    cout << 0;


    return 0;
    }