using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        public static bool[,] matrix,passed;

        static void Main(string[] args)
        {
            int times = int.Parse(Console.ReadLine());
            matrix = new bool[times, times];
            int counter = 0;
            for (int i = 0; i < times; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < times; j++)
                {
                    if (s[j] == '#')
                    {
                        matrix[i, j] = true;
                        counter++;
                    }
                }
            }
            if (counter % 5 != 0)
            {
                Console.WriteLine("NO");
                return;
            }
            Console.WriteLine(check()?"YES":"NO");
        }

        public static bool check_square(int i, int j)
        {
            if (i >= 0 && i < matrix.GetLength(0) && j >= 0 && j < matrix.GetLength(0))
            {
                return matrix[i, j];
            }
            return false;
        }

        public static bool check_center(int i, int j)
        {
            bool valid = check_square(i + 1, j) && check_square(i, j) && check_square(i - 1, j) && check_square(i, j - 1) && check_square(i, j + 1);
            if (valid)
            {
                passed[i, j] = true;
                passed[i, j + 1] = true;
                passed[i, j - 1] = true;
                passed[i + 1, j] = true;
                passed[i - 1, j] = true;
                return true;
            }
            return false;
        }

        public static bool valid(int i, int j)
        {
            if (matrix[i, j] == false)
                return true;

            if (check_center(i, j) || check_center(i - 1, j) || check_center(i + 1, j) || check_center(i, j - 1) || check_center(i, j + 1))
            {
                return true;
            }
            return false;

        }

        public static bool check()
        {
            passed = new bool[matrix.GetLength(0), matrix.GetLength(1)];
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (!passed[i,j])
                    {
                        if (!valid(i,j))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
}