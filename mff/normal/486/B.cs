using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] d = Console.ReadLine().Split();
            int m = int.Parse(d[0]);
            int n = int.Parse(d[1]);
            int[,] B = new int[m, n];
            int[,] A = new int[m, n];
            int[,] C = new int[m, n];
            for (int i = 0; i < m; i++)
            {
                d = Console.ReadLine().Split();
                for (int j = 0; j < n; j++)
                {
                    B[i, j] = int.Parse(d[j]);
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int a = B[i, j];
                    for (int k = 0; k < m && a == 1; k++)
                    {
                        a *= B[k, j];
                    }
                    for (int k = 0; k < n && a == 1; k++)
                    {
                        a *= B[i, k];
                    }
                    A[i, j] = a;
                }
            }


            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int a = A[i, j];
                    for (int k = 0; k < m && a == 0; k++)
                    {
                        a += A[k, j];
                    }
                    for (int k = 0; k < n && a == 0; k++)
                    {
                        a += A[i, k];
                    }
                    C[i, j] = a;
                }
            }
            bool v = true;
            for (int i = 0; i < m && v; i++)
            {
                for (int j = 0; j < n && v; j++)
                {
                    if (B[i, j] != C[i, j])
                    {
                        v = false;
                        break;
                    }
                }
            }
            if (v)
            {
                Console.WriteLine("YES");
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n-1; j++)
                    {
                        Console.Write(A[i,j]+" ");
                    }
                    Console.WriteLine(A[i, n-1]);
                }
            }
            else
                Console.WriteLine("NO");
        }
    }
}