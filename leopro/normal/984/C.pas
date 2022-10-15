var
  n, i: Int32;
  p, q, b, primes: array [1..100000] of Int64;
  gcd: Int64;
  
function NOD(a, b: Int64): Int64;
var
  tmp: Int64;
begin
  If a < b then
  begin
    tmp := a;
    a := b;
    b := tmp;
  end;
  If b=0 then Result:=a else Result:=NOD(a mod b, b);
end;

begin
  ReadLn(n);
  For i := 1 to n do 
  begin
    ReadLn(p[i], q[i], b[i]);
  end;
  For i := 1 to n do
  begin
    gcd := NOD(p[i], q[i]);
    q[i] := q[i] div gcd;
    gcd := b[i];
    While gcd > 1 do
    begin
      While q[i] mod gcd = 0 do q[i] := q[i] div gcd;
      gcd := NOD(q[i], b[i]);
    end;
    If q[i] = 1 then WriteLn('Finite') else WriteLn('Infinite');
  end;
end.