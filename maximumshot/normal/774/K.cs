using System;
class Program
{
    static void Main()
    {
        string str;
        string ans="";
        bool e=true;
        bool o = true;
        int n = Convert.ToInt32(Console.ReadLine());
        
            str = Console.ReadLine();
            Console.Write(str[0]);
            for(var i=1; i<n; i++)
            {
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
                {
                   
                         if( str[i]!=str[i-1])
                        {
                            e = true;
                            o = true;
                            Console.Write(str[i]);
                            continue;
                        }

                      
                          if (str[i]=='e' && e)
                          {
                              if (i != n - 1) { if (str[i + 1] != 'e') { Console.Write(str[i]); } else e = false; }
                              else Console.Write(str[i]);
                              o = true;
                              
                          }

                          if(str[i]=='o' && o)
                          {
                              if (i != n - 1) { if (str[i + 1] != 'o') { Console.Write(str[i]); } else o = false; }
                              else Console.Write(str[i]); ;
                              e = true;
                          }        
                }
                else
                {
                    e = true;
                    o = true;
                    Console.Write(str[i]);
                }

            }
          
               
               // int tmp = Convert.ToInt32(Console.ReadLine());
        


    }

}