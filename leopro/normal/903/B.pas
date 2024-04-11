program Project1;

var
  a1, c1, h1, h2, a2, number: LongInt;
  HowToWin: WideString;

begin
  Read(h1, a1, c1);
  ReadLn;
  Read(h2, a2);
  ReadLn;
  HowToWin:='';
  number:=0;
  While h2 > 0 do
  begin
    //Vova's attack
    If (h1 <= a2) and (h2 > a1) then
    begin
      HowToWin:=HowToWin + #13#10 + 'HEAL';
      h1 := h1 + c1;
    end else
    begin
      HowToWin:=HowToWin + #13#10 + 'STRIKE';
      h2 := h2 - a1
    end;
    inc(number);
    //ModCrab's attack
    If h2 <= 0 then Break else
    begin
      h1 := h1 - a2;
    end;
  end;
  Write(number);
  WriteLn(HowToWin);
  ReadLn;
end.