program Project1;

var
  k, n, w, i, x: LongInt;

begin
  Read(k); Read(n); ReadLn(w);
  For i := w-1 downto 1 do w := w+i;
  k := w*k;
  x := k-n;
  If x < 0 then x := 0;
  WriteLn(x); 
end.