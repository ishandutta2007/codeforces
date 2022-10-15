program Project1;

var
  n, k: Int64;

begin
  Read(n); ReadLn(k);
  If k > n - (n div 2) then k := (k - (n - (n div 2)))*2 else k := k*2-1;
  WriteLn(k); 
end.