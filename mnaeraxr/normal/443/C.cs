using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        static bool[,] M;
        static int[,] N;
        static bool[] C;

        static void Main()
        {
            M = new bool[5,5];
            N = new int[5,5];
            C = new bool[10];
            
            string l = "RGBYW";
            int times = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split();
            for (int i = 0; i < times; ++i)
            {
                string s = p[i];
                int t = -1;
                for (int j = 0; j < 5; ++j)
                {
                    if (s[0] == l[j])
                        t = j;
                }
                M[t,int.Parse(s[1].ToString()) - 1] = true;
            }
            Console.WriteLine(BT(0));
        }

        static int BT(int level)
        {
            if (valid())
                return level;

            int num = (int)Math.Pow(2, level);
            int pistas = 20;
            for (int i = 0; i < 10; ++i)
            {
                if (!C[i])
                {
                    C[i] = true;
                    if (i / 5 == 0)
                    {
                        for (int j = 0; j < 5; ++j)
                        {
                            N[i, j] += num;
                        }
                    }
                    else
                    {
                        for (int j = 0; j < 5; ++j)
                        {
                            N[j , i - 5] += num;
                        }
                    }
                    int cur_pistas = BT(level + 1);

                    if (cur_pistas < pistas)
                        pistas = cur_pistas;

                    C[i] = false;
                    if (i / 5 == 0)
                    {
                        for (int j = 0; j < 5; ++j)
                        {
                            N[i, j] -= num;
                        }
                    }
                    else
                    {
                        for (int j = 0; j < 5; ++j)
                        {
                            N[j, i - 5] -= num;
                        }
                    }

                }
            }
            return pistas;
        }

        static bool valid()
        {
            bool[] q = new bool[4000];
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    if (M[i, j])
                    {
                        if (q[N[i, j]])
                            return false;
                        q[N[i, j]] = true;
                    }
                }
            }
            return true;
        }
    }
}