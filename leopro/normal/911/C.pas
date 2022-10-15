var
  k1, k2, k3, x1, x2, x3, second: LongInt;
  Possible: Boolean;

procedure Sort(var a, b: LongInt);
var
  tmp: LongInt;
begin
  If a > b then
  begin
    tmp := a;
    a := b;
    b := tmp;
  end;
end;

procedure Yes(Cond: Boolean);
begin
  If Cond then WriteLn('YES') else WriteLn('NO');
end;

begin
  Read(k1, k2, k3);
  ReadLn;
  Possible := True;
  Sort(k2, k3);
  Sort(k1, k2);
  Sort(k2, k3);

  If k3 > 10 then
  begin
    For x1 := 0 to 20 do
    begin
      For x2 := 0 to 20 do
      begin
        Possible := True;
        For second := 1 to 40 do
        begin
          If ((second - x1) mod k1 <> 0) and ((second - x2) mod k2 <> 0) then Possible:=False;
        end;
        If Possible = True then Break;
      end;
      If Possible = True then Break;
    end;
  end else
  begin
    For x1 := 0 to 10 do
    begin
      For x2 := 0 to 10 do
      begin
        For x3 := 0 to 10 do
        begin
          Possible:=True;
          For second := 0 to 20 do
          begin
            If ((second-x1) mod k1 <> 0) and ((second-x2) mod k2 <> 0) and ((second-x3) mod k3 <> 0) then Possible:=False;
          end;
          If Possible = True then Break;
        end;
        If Possible = True then Break;
      end;
      If Possible = True then Break;
    end;
  end;

  Yes(Possible);
  ReadLn;
end.