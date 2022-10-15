program Project1;

var
  s: string;
  n, i: LongInt;
  CanHello: Boolean;

begin
  ReadLn(s);
  CanHello:=True;
  
  n := Pos('h', s);
  If n = 0 then CanHello:=False else Delete(s, 1, n);
  n := Pos('e', s);
  If n = 0 then CanHello:=False else Delete(s, 1, n);
  n := Pos('l', s);
  If n = 0 then CanHello:=False else Delete(s, 1, n);
  n := Pos('l', s);
  If n = 0 then CanHello:=False else Delete(s, 1, n);
  n := Pos('o', s);
  If n = 0 then CanHello:=False else Delete(s, 1, n);
  
  If CanHello then WriteLn('YES') else WriteLn('NO'); readln;
end.