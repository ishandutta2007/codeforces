using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            bool[] T = new bool[50];
            string[] s = Console.ReadLine().Split(',',' ','{','}');
            if (s.Length == 0)
                Console.WriteLine("0");
            else
            {
                int counter = 0;
                for (int i = 0; i < s.Length; ++i)
                {
                    if (s[i] == "")
                        continue;
                    if (!T[s[i][0] - 'a'])
                    {
                        counter++;
                        T[s[i][0]- 'a'] = true;
                    }
                }
                Console.WriteLine(counter);
            }
        }
    }
}