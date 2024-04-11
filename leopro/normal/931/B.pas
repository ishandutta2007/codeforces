var
  a, b, n, i, ans: Int32;

function Power(base, exponent: LongInt): LongInt;
var
  i, Res: LongInt;
begin
  Res := 1;
  For i := 1 to exponent do
  begin
    Res := Res * base;
  end;
  Result := Res;
end;

  
begin
  ReadLn(n, a, b);
  dec(a); dec(b);
  i := 2;
  ans := 1; 
  While i < n do
  begin
    If a div i = b div i then Break;
    i := i * 2;
    inc(ans);
  end;
  If Power(2, ans) = n then WriteLn('Final!') else WriteLn(ans);
end.