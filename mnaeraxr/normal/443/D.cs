using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        static double[] NUMS;
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            NUMS = new double[100];
            string[] s = Console.ReadLine().Split();

            for (int i = 0; i < n; ++i)
            {
                NUMS[i] = double.Parse(s[i].Replace('.',','));
            }
            Array.Sort(NUMS);
            double Pp = NUMS[NUMS.Length - 1];
            double Sp = 1 - Pp;

            for (int i = NUMS.Length - 2; i >= 0; --i)
            {
                double Ppt = Pp*(1 - NUMS[i]) + Sp*NUMS[i];
                if (Ppt > Pp)
                {
                    Pp = Ppt;
                    Sp = Sp * (1 - NUMS[i]);
                }
            }
            Console.WriteLine(Math.Round(Pp,10).ToString("0.000000000").Replace(',','.'));
        }
    }
}