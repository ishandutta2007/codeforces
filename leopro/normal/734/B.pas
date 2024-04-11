program Project1;

var
  k2, k3, k5, k6: LongInt;
  sum: Int64;

begin
  Read(k2); Read(k3); Read(k5); ReadLn(k6);
  If k5<k6 then k6 := k5;  
  If k2 > k6 then
  begin
    k5 := k2-k6;
    sum := 256*k6;
    If k5 > k3 then sum := sum + 32*k3 else sum := sum + 32 * k5;
  end else
  begin
    sum := 256*k2;
  end;
  WriteLn(sum);
end.